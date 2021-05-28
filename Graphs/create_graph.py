import networkx as nx
import matplotlib.pylab as pl

#
# G = nx.Graph()
# G.add_edge(1, 2)
# G.add_edge(2, 3)


def draw(G, labels):
    # get positions
    pos = nx.spring_layout(G)
    # print(pos)
    nx.draw(G, pos, with_labels=True)

    # shift position a little bit
    shift = [0.1, 0]
    shifted_pos = {node: node_pos + shift for node, node_pos in pos.items()}

    # Just some text to print in addition to node ids
    # labels = {1: 'First Node', 2: 'Second Node', 3: 'Third Node'}
    nx.draw_networkx_labels(G, shifted_pos, labels=labels, horizontalalignment="left")

    # adjust frame to avoid cutting text, may need to adjust the value
    axis = pl.gca()
    axis.set_xlim([1.5 * x for x in axis.get_xlim()])
    axis.set_ylim([1.5 * y for y in axis.get_ylim()])
    # turn off frame
    pl.axis("off")

    pl.show()
