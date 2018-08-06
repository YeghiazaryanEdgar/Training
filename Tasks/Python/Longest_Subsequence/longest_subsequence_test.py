#!/usr/bin/env python3

import unittest
import longest_subsequence

class SubsequenceWords(unittest.TestCase):


    def test_is_subseq(self):
        self.assertEqual(longest_subsequence.is_subseq('Albert Einstein was born in 1879.', 'AEwi'), 1)
        self.assertEqual(longest_subsequence.is_subseq('Albert Einstein was born in 1879.', 's bi.'), 1)
        self.assertEqual(longest_subsequence.is_subseq('Albert Einstein was born in 1879.', ' 18'), 1)
        self.assertEqual(longest_subsequence.is_subseq('Albert Einstein was born in 1879.', 't173'), 0)


    def test_longest_subseqs(self):
        self.assertEqual(longest_subsequence.longest_subseqs('Albert Einstein was born in 1879.', ['Alwab', 'Eis', 'jjj', 'E 18']), ['Alwab'])


if __name__ == '__main__':
    unittest.main()

