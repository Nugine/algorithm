import matplotlib.pyplot as plt
import networkx as nx
from pprint import pprint
from queue import PriorityQueue
import time
import numpy as np

graph = nx.Graph()


def build_graph(edges):
    for u, v, w in edges:
        graph.add_edge(u, v, weight=w)


if __name__ == "__main__":
    build_graph(edges=[
        ("a", "b", 4),
        ("a", "h", 8),
        ("b", "c", 8),
        ("b", "h", 1),
        ("c", "d", 7),
        ("c", "f", 4),
        ("c", "i", 2),
        ("d", "e", 9),
        ("d", "f", 14),
        ("e", "f", 10),
        ("f", "g", 2),
        ("g", "h", 1),
        ("g", "i", 6),
        ("h", "i", 7),
    ])

    INF = 10000

    dis = {v: INF for v in graph}
    vis = []
    q = PriorityQueue()

    dis["a"] = 0
    q.put((0, "a"))

    plt.show(block=False)
    pos = {
        "a": np.array([-0.75,  0.00]),
        "b": np.array([-0.50,  0.25]),
        "c": np.array([0.00,  0.25]),
        "d": np.array([0.50,  0.25]),
        "e": np.array([0.75,  0.00]),
        "f": np.array([0.50, -0.25]),
        "g": np.array([0.00, -0.25]),
        "h": np.array([-0.50, -0.25]),
        "i": np.array([-0.25,  0.00]),
    }
    labels_pos = {
        "a": pos["a"]+[-0.04, -0.04],
        "b": pos["b"]+[0, 0.04],
        "c": pos["c"]+[0, 0.04],
        "d": pos["d"]+[0, 0.04],
        "e": pos["e"]+[0.04, -0.04],
        "f": pos["f"]+[0, -0.04],
        "g": pos["g"]+[0, -0.04],
        "h": pos["h"]+[0, -0.04],
        "i": pos["i"]+[-0.04, 0.04],
    }

    while not q.empty():
        _, u = q.get()

        if u in vis:
            continue
        vis.append(u)

        relaxed = []
        for v, attr in graph[u].items():
            w = attr["weight"]
            if dis[v] > dis[u] + w:
                dis[v] = dis[u] + w
                q.put((dis[v], v))
                relaxed.append(v)

        print(f"dis: {list(dis.values())}")
        print(f"q: {q.queue}")
        print(f"vis: {vis}")

        plt.clf()

        edge_labels = nx.get_edge_attributes(graph, 'weight')
        node_labels = {
            n: f"dis={d if d < INF else '∞'}" for n, d in dis.items()}
        node_colors = [
            "#F08080" if n == u else "#53e818" if n in relaxed else "white" for n in graph]

        nx.draw(graph, pos, node_color=node_colors, with_labels=True,
                edgecolors="black", node_size=1000)
        nx.draw_networkx_edge_labels(graph, pos, edge_labels=edge_labels)
        nx.draw_networkx_labels(
            graph, labels_pos, labels=node_labels, font_size=10)

        plt.pause(0.01)
        plt.savefig(f"1-{len(vis)}.png")
        time.sleep(0.8)
        print()

    print(f"final dis: {dis}")
