#!/usr/bin/env python3

import unittest
import unit

class TestCalc(unittest.TestCase):

    def test_add(self):   # test_ is required
        self.assertEqual(unit.add(10, 5), 15)
        self.assertEqual(unit.add(-1, 1), 0)
        self.assertEqual(unit.add(-1, -5), -6)

    def test_sub(self):   # test_ is required        
        self.assertEqual(unit.sub(10, 5), 5)
        self.assertEqual(unit.sub(-1, 1), -2)
        self.assertEqual(unit.sub(-1, -5), 4)

    def test_mult(self):   # test_ is required        
        self.assertEqual(unit.mult(10, 5), 50)
        self.assertEqual(unit.mult(-1, 1), -1)
        self.assertEqual(unit.mult(-1, -5), 5)

    def test_div(self):   # test_ is required        
        self.assertEqual(unit.div(10, 5), 2)
        self.assertEqual(unit.div(-1, 1), -1)
        self.assertEqual(unit.div(-1, -5), 0.2)
        
        # self.assertRaises(ValueError, unit.div, 10, 2)  # 0
        with self.assertRaises(ValueError):
            unit.div(10, 0)


if __name__ == '__main__':
    unittest.main()
