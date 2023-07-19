def mapper(data):
    words = data.split()
    for word in words:
        yield word, 1

def reducer(key, values):
    yield key, sum(values)

data = "apple orange apple banana apple orange"
word_counts = {}

for key, value in mapper(data):
    word_counts.setdefault(key, []).append(value)

for key, values in word_counts.items():
    for result_key, result_value in reducer(key, values):
        print(f"{result_key}: {result_value}")
