#!/usr/bin/env python3

import unittest
import sys

def is_palindrome(s: str) -> bool:
    l = 0
    r = len(s) - 1
    while l< r:
        if s[l] != s[r]:
            return False
        l += 1
        r -= 1
    return True


class PalindromeRecursive():
    def __init__(self, s: str):
        self.start = 0
        self.phrase = s

    def run(self) -> bool:
        return self.inner(self.phrase)

    def inner(self, s: str) -> bool:
        if s == "":
            return True

        ok = self.inner(s[1:])
        if not ok:
            return False

        if self.phrase[self.start] != s[0]:
            return False

        self.start += 1
        return True


def is_palindrome_recursive(s: str) -> bool:
    checker = PalindromeRecursive(s)
    return checker.run()


class PalindromeTest(unittest.TestCase):
    def test_two_pointer(self):
        self.assertTrue(is_palindrome('racecar'))
        self.assertFalse(is_palindrome('poopy'))

    def test_recursive(self):
        self.assertTrue(is_palindrome_recursive('racecar'))

if __name__ == "__main__":
    verbosity = 1
    if len(sys.argv) == 2 and sys.argv[1] == "-v":
        verbosity = 2

    unittest.main(verbosity=verbosity)
