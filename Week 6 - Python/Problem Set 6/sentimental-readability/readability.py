import cs50


def count_sentences(text):
    total_sentences = 0
    for char in text:
        if char in [".", "?", "!"]:
            total_sentences += 1
    return total_sentences


def count_letters(text):
    total_letters = 0
    for char in text:
        if char.isalpha():
            total_letters += 1
    return total_letters


def count_words(text):
    total_words = 1  # Assuming there is at least one word
    for char in text:
        if char.isspace():
            total_words += 1
    return total_words


def main():
    input_text = input("Text: ")

    letters = count_letters(input_text)
    sentences = count_sentences(input_text)
    words = count_words(input_text)

    L = (letters / words) * 100
    S = (sentences / words) * 100

    index = round(0.0588 * L - 0.296 * S - 15.8)

    if index < 1:
        print("Before Grade 1")
    elif index >= 16:
        print("Grade 16+")
    else:
        print(f"Grade {index}")


if __name__ == "__main__":
    main()
