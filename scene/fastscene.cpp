#include "primitive/primitive.h"
#include "scene/fastscene.h"
#include "shader/shader.h"
#include <algorithm>
#include <iostream>

int Node::countNodeIntersections(const Ray &ray, float t0, float t1) const {
  // IMPLEMENT ME
  return 0;
}

bool Node::findIntersection(Ray &ray, float t0, float t1) const {
  // IMPLEMENT ME
  // If this is a leaf node, we intersect with all the primitives...
  // ... otherwise we continue through the branches
  // Determine the order in which we intersect the child nodes
  // Traverse the necessary children
  return false;
}

bool Node::findOcclusion(Ray &ray, float t0, float t1) const {
  // IMPLEMENT ME
  return false;
}

int FastScene::countNodeIntersections(const Ray &ray) const {
  // IMPLEMENT ME
  return false;
}

bool FastScene::findIntersection(Ray &ray) const {
  // IMPLEMENT ME
  return false;
}

bool FastScene::findOcclusion(Ray &ray) const {
  // IMPLEMENT ME
  return false;
}

void FastScene::buildTree(int maximumDepth, int minimumNumberOfPrimitives) {
  // IMPLEMENT ME
  // Set the new depth and number of primitives

  // Determine the bounding box of the kD-Tree

  // Recursively build the kD-Tree
}

std::unique_ptr<Node> FastScene::build(Vector3d const &minimumBounds, Vector3d const &maximumBounds, const std::vector<std::shared_ptr<Primitive>> &primitives, int depth) {
  // IMPLEMENT ME
  // Determine the diameter of the bounding box

  // Test whether we have reached a leaf node...

  // ... otherwise create a new inner node by splitting through the widest
  // dimension

  // Determine the split position
  // Note: Use the median of the minimum bounds of the primitives

  // Divide primitives into the left and right lists
  // Remember: A primitive can be in both lists!
  // Also remember: You split exactly at the minimum of a primitive,
  // make sure *that* primitive does *not* appear in both lists!

  // Print out the number of primitives in the left and right child node

  // Set the left and right split vectors

  // Recursively build the tree
  return nullptr;
}
