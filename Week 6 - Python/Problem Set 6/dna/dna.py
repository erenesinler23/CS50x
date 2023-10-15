import csv
import sys


def main():
    # Check for command-line usage
    if len(sys.argv) != 3:
        print("Usage: python dna.py CSV_FILE TEXT_FILE")
        sys.exit(1)

    database = []
    results = {}

    # Read database file into a variable
    with open(sys.argv[1]) as file:
        reader = csv.reader(file)
        header = next(reader)  # Read the header row
        database = [row for row in reader]

    # Read DNA sequence file into a variable
    with open(sys.argv[2]) as file:
        sequence = file.read()

    # Find longest match of each STR in DNA sequence
    for i in range(1, len(header)):
        sub = header[i]
        results[sub] = longest_match(sequence, sub)

    seq_dna = [results[sub] for sub in header[1:]]

    # Check database for matching profiles
    for person in database:
        person_dna = [int(i) for i in person[1:]]

        if person_dna == seq_dna:
            print(person[0])
            sys.exit(0)

    print("No match")


def longest_match(sequence, subsequence):
    """Returns length of the longest run of subsequence in sequence."""
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    for i in range(sequence_length):
        count = 0
        start = i
        end = i + subsequence_length

        while sequence[start:end] == subsequence:
            count += 1
            start = end
            end = start + subsequence_length

        longest_run = max(longest_run, count)

    return longest_run


if __name__ == "__main__":
    main()
