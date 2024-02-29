#!/usr/bin/env python3

import socket
import signal
import selectors
import time

interrupt_read, interrupt_write = socket.socketpair()


def sigint_handler(signum, _):
    print("RECEIVED SIGNAL:", signum)
    interrupt_write.send(b'\0')

signal.signal(signal.SIGINT, sigint_handler)


class MyServer:

    def __init__(self) -> None:
        self._socket = socket.socket()
        self.server_address = ('localhost', 10000)
        self._socket.bind(self.server_address)
        self._socket.listen()
        print(f"Listening on {self.server_address[0]}:{self.server_address[1]}")

    def socket(self) -> int:
        return self._socket.fileno()

    def handle(self) -> None:
        connection, client_address = self._socket.accept()
        try:
            data = connection.recv(16)
            print(client_address, "says:", data)
        finally:
            connection.close()

    def close(self) ->  None:
        self._socket.close()


def main(server):
    selector = selectors.DefaultSelector()
    selector.register(interrupt_read, selectors.EVENT_READ)
    selector.register(server.socket(), selectors.EVENT_READ)

    should_close = False
    while not should_close:
        for key, _ in selector.select():
            if key.fileobj == interrupt_read:
                should_close = True
                break
            elif key.fileobj == server.socket():
                server.handle()
            else:
                print("UNKNOWN key", key.fileobj)
    selector.close()

if __name__ == "__main__":
    server = MyServer()
    main(server)
    server.close()
    print("we exited!")
