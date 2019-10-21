import json
import socket

class UnixDomainSocketRpc(object):
    def __init__(self, socket_path, executor=None, logger=logging, encoder_cls=json.JSONEncoder, decoder=json.JSONDecoder()):
        self.socket_path = socket_path
        self.encoder_cls = encoder_cls
        self.decoder = decoder
        self.executor = executor
        self.logger = logger

        self.next_id = 0

    def _writeobj(self, sock, obj):
        s = json.dumps(obj, cls=self.encoder_cls)
        sock.sendall(bytearray(s, 'UTF-8'))

    def _readobj(self, sock, buff=b''):
        """Read a JSON object, starting with buff; returns object and any buffer left over"""
        while True:
            parts = buff.split(b'\n\n', 1)
            if len(parts) == 1:
                # Didn't read enough.
                b = sock.recv(max(1024, len(buff)))
                buff += b
                if len(b) == 0:
                    return {'error': 'Connection to RPC server lost.'}, buff
            else:
                buff = parts[1]
                obj, _ = self.decoder.raw_decode(parts[0].decode("UTF-8"))
                return obj, buff

    def __getattr__(self, name):
        """Intercept any call that is not explicitly defined and call @call
        We might still want to define the actual methods in the subclasses for
        documentation purposes.
        """
        name = name.replace('_', '-')

        def wrapper(*args, **kwargs):
            if len(args) != 0 and len(kwargs) != 0:
                raise RpcError("Cannot mix positional and non-positional arguments")
            elif len(args) != 0:
                return self.call(name, payload=args)
            else:
                return self.call(name, payload=kwargs)
        return wrapper

    def call(self, method, payload=None):
        self.logger.debug("Calling %s with payload %r", method, payload)

        if payload is None:
            payload = {}
        # Filter out arguments that are None
        if isinstance(payload, dict):
            payload = {k: v for k, v in payload.items() if v is not None}

        # FIXME: we open a new socket for every readobj call...
        sock = socket.socket(socket.AF_UNIX, socket.SOCK_STREAM)
        sock.connect(self.socket_path)
        self._writeobj(sock, {
            "method": method,
            "params": payload,
            "id": self.next_id,
        })
        self.next_id += 1
        resp, _ = self._readobj(sock)
        sock.close()

        self.logger.debug("Received response for %s call: %r", method, resp)
        if not isinstance(resp, dict):
            raise ValueError("Malformed response, response is not a dictionary %s." % resp)
        elif "error" in resp:
            raise RpcError(method, payload, resp['error'])
        elif "result" not in resp:
            raise ValueError("Malformed response, \"result\" missing.")
        return resp["result"]
