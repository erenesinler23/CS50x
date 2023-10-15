import cs50


def main():
    height = get_int()

    for i in range(height):
        for j in range(height - i - 1):
            print(" ", end="")

        for s in range(i + 1):
            print("#", end="")
        print("")


def get_int():
    while True:
        x = cs50.get_int("Height: ")
        if x > 0 and x < 9:
            break
    return x


main()
