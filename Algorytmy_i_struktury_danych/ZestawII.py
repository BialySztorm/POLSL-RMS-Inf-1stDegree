from random import randint


def build_bad_char_table(pattern):
    bad_char = {}
    pattern_len = len(pattern)
    for i in range(pattern_len - 1):
        bad_char[pattern[i]] = pattern_len - i - 1
    return bad_char


def boyer_moore(text, pattern):
    result = []
    text_len = len(text)
    pattern_len = len(pattern)
    if pattern_len == 0:
        return result

    bad_char = build_bad_char_table(pattern)
    i = 0
    while i <= text_len - pattern_len:
        j = pattern_len - 1
        while j >= 0 and pattern[j] == text[i + j]:
            j -= 1
        if j < 0:
            result.append(i)
            i += pattern_len
        else:
            if text[i + j] in bad_char:
                i += max(1, j - bad_char[text[i + j]])
            else:
                i += pattern_len
    return result


def rabin_karp(text, pattern):
    result = []
    text_len = len(text)
    pattern_len = len(pattern)
    if pattern_len == 0:
        return result

    # Wybierz wartość modulo dużą liczbę pierwszą
    prime = 101

    # Oblicz hasz wzorca i hasz pierwszego okna tekstu
    pattern_hash = 0
    text_hash = 0
    for i in range(pattern_len):
        pattern_hash = (pattern_hash + ord(pattern[i])) % prime
        text_hash = (text_hash + ord(text[i])) % prime

    for i in range(text_len - pattern_len + 1):
        if pattern_hash == text_hash:
            match = True
            for j in range(pattern_len):
                if pattern[j] != text[i + j]:
                    match = False
                    break
            if match:
                result.append(i)

        if i < text_len - pattern_len:
            # Oblicz hasz dla kolejnego okna tekstu
            text_hash = (text_hash - ord(text[i]) + ord(text[i + pattern_len])) % prime
            if text_hash < 0:
                text_hash += prime

    return result


def bubblesort(tab):
    n = len(tab)
    for i in range(n - 1):
        for j in range(n - 1, i, -1):
            if tab[j] < tab[j - 1]:
                tab[j], tab[j - 1] = tab[j - 1], tab[j]
    return tab


def partition(tab, left, right):
    pivot = tab[left]
    low = left + 1
    high = right

    done = False
    while not done:
        while low <= high and tab[low] <= pivot:
            low = low + 1
        while tab[high] >= pivot and high >= low:
            high = high - 1
        if high < low:
            done = True
        else:
            tab[low], tab[high] = tab[high], tab[low]
    tab[left], tab[high] = tab[high], tab[left]

    return high


def quicksort(tab, left, right):
    if left < right:
        pivot = partition(tab, left, right)
        quicksort(tab, left, pivot - 1)
        quicksort(tab, pivot + 1, right)
    return tab


tab1 = ""
size1 = 5
for i in range(20):
    tab1 += str(chr(ord('A') + randint(1, size1) - 1))

print(tab1)
print(boyer_moore(tab1, "AB"))
print(rabin_karp(tab1, "AB"))
tab2 = []
size2 = 30
for i in range(20):
    tab2.append(randint(1, size2))

print(tab2)
print(bubblesort(tab2))
print(quicksort(tab2, 0, len(tab2) - 1))
