natural_number_set = set(range(1, 101))
generated_number_set = set()

for i in range(1, 101):
    print('currnet i = ' + str(i))
    for j in str(i):
        print('currnet j = ' + str(j))
        i = i + int(j)
    print('**managed num = ' + str(i))
    generated_number_set.add(i)
    print()

print(generated_number_set)
print(natural_number_set)

self_numbers_set = natural_number_set - generated_number_set
print(sorted(self_numbers_set))
 
