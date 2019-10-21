import os
import sys
import logging
sys.path.append( '../util/wrappers/python' )
import server

class server_testsuite:

    def __init__():
        initlog()
    
    def initlog():
        # Init logging
        self.logger = logging.getLogger(__name__)
        self.logger.setLevel(logging.DEBUG)
        ch = logging.StreamHandler()
        ch.setLevel(logging.DEBUG)
        f = logging.Formatter('%(asctime)s - %(name)s - %(levelname)s - %(message)s')
        ch.setFormatter(f)
        self.logger.addHandler(ch)
        self.logger.info("Logging initialised")

    initlog()

    # Init test suite
    def setup():
        logger.info("Setup {}".format(__name__))
        logger.debug("Working directory: {}".format(os.getcwd()))

    # Execute testsuite
    def runtests():
        logger.info("Runtests {}".format(__name__))
        test_bind_port()

    # Cleardown testsuite
    def teardown():
        logger.info("Teardown {}".format(__name__))

    # --------------------
    # Tests
    # --------------------
    def test_bind_port():

        # default server
        s = Server()
        assert( s.getPort() == Server.DEFAULT_PORT )  


if __name__ == "__main__":

    st = server_testsuite()
    
    initlog()
    setup()
    runtests()
    teardown()
