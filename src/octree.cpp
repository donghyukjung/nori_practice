#include <nori/accel.h>
#include <nori/mesh.h>
#include <nori/octree.h>
#include <Eigen/Geometry>
#define MAX_DEPTH 10
#define MAX_TRIANGEL_NUM 10

NORI_NAMESPACE_BEGIN

void build_octree(Mesh *mesh) {
	Node *node;
	if (node->m_depth > MAX_DEPTH) return;

	BoundingBox3f *box = node->m_bbox;
	int depth = node->m_depth;
	std::vector<Node*> *childs = node->m_childs;
	std::vector<int> *index = node->m_index;

	Point3f &center = node->m_bbox->getCenter();
	childs = new std::vector<Node*>();
	for (int i = 0;i < 8;i++) {
		int m[3], M[3];
		for (int j = 0;j < 3;j++) {
			m[j] = std::min(box->getCorner(i)[j], center[j]);
			M[j] = std::max(box->getCorner(i)[j], center[j]);
		}
		childs->push_back((
			new Node(
				new BoundingBox3f(
					Point3f(m[0], m[1], m[2]),
					Point3f(M[0], M[1], M[2])
				),
				new std::vector<int>,
				depth + 1
			)
			));
	}

	for (int i = 0;i < index->size(); i++) {
		for (int j = 0;j < 8;j++)
			if ((*childs)[i]->m_bbox->overlaps(mesh->getBoundingBox(i)))
				(*childs)[i]->m_index->push_back(i);
	}

	for (int i = 0;i < 8;i++) {
		int triangel_num = (*childs)[i]->m_index->size();
		if (triangel_num == 0) (*childs)[i] = nullptr;
		else if (triangel_num > MAX_TRIANGEL_NUM)(*childs)[i]->build_octree(mesh);
	}

}
void generate_octree(Mesh *mesh) {

	Octree *tree = new Octree();
	tree->m_mesh = mesh;
	BoundingBox3f bbox = tree->m_mesh->getBoundingBox();
	tree->m_root = new Node(new BoundingBox3f(bbox.min, bbox.max), new std::vector<int>, 0);
	for (int i = 0;i < tree->m_root->m_index->size();i++) tree->m_root->m_index->push_back(i);
	tree->m_root->build_octree(tree->m_mesh);

}

