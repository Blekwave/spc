needle = input()

table = [-1, 0]

for i, c in enumerate(needle[1:], start=1):
    max_prefix = min(table[-1] + 1, len(needle) - 1)
    largest_valid_prefix = 0
    for prefix_size in range(max_prefix, 0, -1):
        suffix = needle[:i+1][-prefix_size:]
        prefix = needle[:prefix_size]
        print("Comparing {} to {} (size {})".format(suffix, prefix, prefix_size))
        if suffix == prefix:
            largest_valid_prefix = prefix_size
            break
    table.append(largest_valid_prefix)

print(table)
