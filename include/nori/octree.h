#include <nori/bbox.h>
#include <nori/mesh.h>
#include <Eigen/Geometry>

#define MAX_DEPTH 8
#define MAX_TRIANGEL_NUM 50

NORI_NAMESPACE_BEGIN

class Octree {
public:
	class Node {
	public:
		// Initialization
		Node(BoundingBox3f *bbox, std::vector<int> *index, int depth)
			:m_bbox{ bbox }, m_index{ index }, m_depth{ depth }{}
		~Node() {}
		// build octree recursively
		void build_octree(Mesh *mesh);
		
		// search octree recursively
		void search(const Ray3f &ray, Mesh *mesh, float &t, int &idx);

		// child nodes of octree
		std::vector<Node*> *m_childs;

		// BoundingBox of each node
		BoundingBox3f *m_bbox;

		// indexes of containing triangles
		std::vector<int> *m_index;

		// depth of node
		int m_depth;
	};

	Node *m_root = nullptr; // root node
	Mesh *m_mesh = nullptr; // mesh pointer

	void generate_octree(Mesh *mesh);
	int search_octree(const Ray3f &ray) const;
};

NORI_NAMESPACE_END