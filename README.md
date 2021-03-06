﻿# DualDataBST
A binary search tree with nodes that hold two data objects.

The DualDataBST is really just a personal experiment, but it does have  a couple of potential uses.

Once such use allows complex objects to be sorted without overriding the comparison operator, simply by assigning associated primitive values to the nodes' primary data. For example, a collection of "customer" objects could be sorted by name, if the names were the also nodes' primary data and the customer objects were the nodes' secondary data.

Another use shows how the data structure could be applied to the object itself. Instead storing the object inside a node, the node design could be written directly into the object. Essentially, the object would serve as its own node. Instead of two data objects, the "node" could have as many data values as necessary. Sticking with the example above, each customer-node could include references to the left and right cusomter-nodes, allowing the BST to treat each customer as a node in and of itself.

I intend to test both of these ideas in the future.

This code can be run with Visual Studio
