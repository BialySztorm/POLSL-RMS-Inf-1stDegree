def is_palindrome(s):
    return s == s[::-1]


toCheck = "kajak"
print("Is 'kajak' a palindrome?")
print(is_palindrome("kajak"))

toCheck = "nie kajak"
print("Is 'nie kajak' a palindrome?")
print(is_palindrome("nie kajak"))
