class SkeletonRpc(UnixDomainSocketRpc):
    """
    RPC client for the `skeletond` daemon.
    This RPC client connects to the `skeletond` daemon through a unix
    domain socket and passes calls through. Since some of the calls
    are blocking, the corresponding python methods include an `async`
    keyword argument. If `async` is set to true then the method
    returns a future immediately, instead of blocking indefinitely.
    This implementation is thread safe in that it locks the socket
    between calls, but it does not (yet) support concurrent calls.
    """
    class SkeletonJSONEncoder(json.JSONEncoder):
        def default(self, o):
            try:
                return o.to_json()
            except NameError:
                pass
            return json.JSONEncoder.default(self, o)

    class SkeletonJSONDecoder(json.JSONDecoder):
        def __init__(self, *, object_hook=None, parse_float=None, parse_int=None, parse_constant=None, strict=True, object_pairs_hook=None):
            self.object_hook_next = object_hook
            super().__init__(object_hook=self.millisatoshi_hook, parse_float=parse_float, parse_int=parse_int, parse_constant=parse_constant, strict=strict, object_pairs_hook=object_pairs_hook)

    def __init__(self, socket_path, executor=None, logger=logging):
        super().__init__(socket_path, executor, logging, self.SkeletonJSONEncoder, self.SkeletonJSONDecoder())

    
    def getinfo(self):
        """
        Show information about this node
        """
        return self.call("getinfo")

        
    def stop(self):
        """
        Shut down the skeletond process
        """
        return self.call("stop")