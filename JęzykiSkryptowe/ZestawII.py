import math
from statistics import median


def calculator():
    try:
        num1 = float(input("Enter the first number: "))
        operator = input("Enter an operator (+, -, *, /) or 'q' to quit: ")
        if operator == 'q':
            return
        num2 = float(input("Enter the second number: "))

        if operator == '+':
            result = num1 + num2
        elif operator == '-':
            result = num1 - num2
        elif operator == '*':
            result = num1 * num2
        elif operator == '/':
            if num2 == 0:
                print("Cannot divide by 0.")
                return
            result = num1 / num2
        else:
            print("Invalid operator.")
            return

        print("Result: ", result)
    except ValueError:
        print("Invalid number format.")


def calculate_stats(numbers):
    if not numbers:
        return None
    total = sum(numbers)
    avg = total / len(numbers)
    med = median(numbers)
    return total, avg, med


def caesar_cipher(text, shift):
    encrypted_text = ""
    for char in text:
        if char.isalpha():
            shift_amount = (ord('A') if char.isupper() else ord('a'))
            encrypted_char = chr((ord(char) - shift_amount + shift) % 26 + shift_amount)
            encrypted_text += encrypted_char
        else:
            encrypted_text += char
    return encrypted_text


def is_palindrome(word):
    word = word.lower().replace(" ", "")
    return word == word[::-1]


def count_spaces(input_file, output_file):
    with open(input_file, "r") as file:
        text = file.read()
        spaces_count = text.count(' ')

    with open(output_file, "w") as file:
        file.write(str(spaces_count))


class Circle:
    def __init__(self, radius):
        self.radius = radius

    def area(self):
        return math.pi * self.radius**2

    def circumference(self):
        return 2 * math.pi * self.radius


class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def distance(self, another_point):
        dx = self.x - another_point.x
        dy = self.y - another_point.y
        return math.sqrt(dx**2 + dy**2)


class TextReverser:
    def reverse_words(self, text):
        words = text.split()
        reversed_text = " ".join(reversed(words))
        return reversed_text


while True:
    print("Choose an option:")
    print("1. Calculator")
    print("2. Calculate Statistics")
    print("3. Caesar Cipher (Encrypt/Decrypt)")
    print("4. Check for Palindrome")
    print("5. Count Spaces in a File")
    print("6. Circle Class")
    print("7. Point Class")
    print("8. Reverse Words in Text")
    print("9. Exit")

    choice = input("Enter the option number: ")

    if choice == "1":
        calculator()
    elif choice == "2":
        numbers = input("Enter numbers separated by spaces: ").split()
        numbers = [int(x) for x in numbers]
        result = calculate_stats(numbers)
        if result:
            total, avg, med = result
            print(f"Total: {total}, Average: {avg}, Median: {med}")
    elif choice == "3":
        text = input("Enter text: ")
        shift = int(input("Enter Caesar shift: "))
        encrypted_text = caesar_cipher(text, shift)
        print("Encrypted text:", encrypted_text)
    elif choice == "4":
        word = input("Enter a word to check: ")
        if is_palindrome(word):
            print("This is a palindrome.")
        else:
            print("This is not a palindrome.")
    elif choice == "5":
        input_file = input("Enter the input file name: ")
        output_file = input("Enter the output file name: ")
        count_spaces(input_file, output_file)
    elif choice == "6":
        radius = float(input("Enter the circle's radius: "))
        circle = Circle(radius)
        print("Circle Area:", circle.area())
        print("Circle Circumference:", circle.circumference())
    elif choice == "7":
        x1 = float(input("Enter x of the first point: "))
        y1 = float(input("Enter y of the first point: "))
        x2 = float(input("Enter x of the second point: "))
        y2 = float(input("Enter y of the second point: "))
        point1 = Point(x1, y1)
        point2 = Point(x2, y2)
        distance = point1.distance(point2)
        print("Distance between points:", distance)
    elif choice == "8":
        text = input("Enter the text to reverse: ")
        reverser = TextReverser()
        reversed_text = reverser.reverse_words(text)
        print(reversed_text)
    elif choice == "9":
        print("Goodbye!")
        break
    else:
        print("Invalid choice. Please select an option from 1 to 9.")
