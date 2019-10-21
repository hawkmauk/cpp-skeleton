import server

def main():
    print("Running integration tests")
    server.setup();
    server.runtests();
    server.teardown();

if __name__ == "__main__":
    main()
