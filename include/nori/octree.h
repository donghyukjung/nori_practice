#include <nori/accel.h>
#include <nori/mesh.h>
#include <Eigen/Geometry>
#define MAX_DEPTH 10
#define MAX_TRIANGEL_NUM 10

NORI_NAMESPACE_BEGIN


class Octree {
public:
	class Node {
	public:
		Node(BoundingBox3f *bbox, std::vector<int> *index, int depth)
			:m_bbox{ bbox }, m_index{ index }, m_depth{ depth }{}
		
		void build_octree(Mesh *mesh);
		
		std::vector<Node*> *m_childs;
		BoundingBox3f *m_bbox;
		std::vector<int> *m_index;
		int m_depth;
	};

	Node *m_root = nullptr;
	Mesh *m_mesh = nullptr;

	void generate_octree(Mesh *mesh);
};
