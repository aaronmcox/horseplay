
def directEmployers(n):
    # since it's from 1 to n, we can just count
    threeCount = 0
    fiveCount = 0

    for i in range(1, n + 1):
        threeCount += 1
        fiveCount += 1

        isMultipleOf3 = threeCount == 3
        isMultipleOf5 = fiveCount == 5

        if isMultipleOf3:
            print("Direct", end="")
            threeCount = 0
        if isMultipleOf5:
            print("Employers", end="")
            fiveCount = 0
        if not isMultipleOf5 and not isMultipleOf3:
            print(i, end="")

        print()


if __name__ == "__main__":
    directEmployers(100)