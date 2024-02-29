#!/usr/bin/env python3

import socket

socket = socket.create_connection(('localhost', 10000))
socket.send(b"Hello world")
socket.close()
