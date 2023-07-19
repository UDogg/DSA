'''
KNN(K-nearest-neighbors)
is a simple classification algorithm based on distance metrics. Here's a basic implementation in Python:
'''
from collections import Counter
import math

def euclidean_distance(point1, point2):
    return math.sqrt(sum((a - b) ** 2 for a, b in zip(point1, point2)))

def k_nearest_neighbors(data, query_point, k=3):
    distances = [(euclidean_distance(features, query_point), label) for features, label in data]
    sorted_distances = sorted(distances)[:k]
    labels = [label for _, label in sorted_distances]
    return Counter(labels).most_common(1)[0][0]
