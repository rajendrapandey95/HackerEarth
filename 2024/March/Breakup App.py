def main():
    n = int(input())
    chats = [input() for _ in range(n)]
    
    days = [0] * 31
    
    for chat in chats:
        weight = 0
        if chat[0] == 'G':
            weight = 2
        else:
            weight = 1

        words = chat.split()
        for word in words:
            if word.isdigit():
                number = int(word)
                days[number] += weight

    max_val = days[0]
    max_date = 0
    for i in range(1, 31):
        if max_val < days[i]:
            max_val = days[i]
            max_date = i

    max_days = sum(1 for val in days if val == max_val)

    if max_days > 1:
        print("No Date")
    elif max_date == 19 or max_date == 20:
        print("Date")
    else:
        print("No Date")


if __name__ == "__main__":
    main()
