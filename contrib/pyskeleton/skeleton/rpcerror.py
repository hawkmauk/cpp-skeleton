class RpcError(ValueError):
    def __init__(self, method, payload, error):
        super(ValueError, self).__init__("RPC call failed: method: {}, payload: {}, error: {}"
                                         .format(method, payload, error))

        self.method = method
        self.payload = payload
        self.error = error