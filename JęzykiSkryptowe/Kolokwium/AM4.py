import math


class Punkt:
    def __init__(self, x, y):
        if not isinstance(x, (int, float)) or not isinstance(y, (int, float)):
            raise ValueError("The x and y values ​​must be numbers")
        self.x = x
        self.y = y


def calculate_distance(p1, p2):
    return math.sqrt((p1.x - p2.x)**2 + (p1.y - p2.y)**2)


# Test
try:
    p1 = Punkt(0, 0)
    p2 = Punkt(3, 4)
    print("Distance between", p1.x, ";", p1.y, "and", p2.x, ";", p2.y, "is:")
    print(calculate_distance(p1, p2))
except ValueError as e:
    print(e)
