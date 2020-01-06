

#include <nori/mesh.h>
#include <nori/octree.h>


NORI_NAMESPACE_BEGIN

typedef Octree::Node Oct_Node;
void Oct_Node::build_octree(Mesh *mesh) {
	
	
	if (m_depth > MAX_DEPTH) return;

	BoundingBox3f *box = m_bbox;

	int depth = m_depth;
	std::vector<Oct_Node*> *childs = m_childs;
	std::vector<int> *index = m_index;


	Point3f center = m_bbox->getCenter();
	childs = new std::vector<Oct_Node*>();
	for (int i = 0;i < 8;i++) {
		float m[3], M[3];
		for (int j = 0;j < 3;j++) {
			m[j] = std::min(box->getCorner(i)[j], center[j]);
			M[j] = std::max(box->getCorner(i)[j], center[j]);
		}
		childs->push_back((
			new Oct_Node(
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
			if ((*childs)[j]->m_bbox->overlaps(mesh->getBoundingBox(i)))
				(*childs)[j]->m_index->push_back(i);
		
	}
	if (depth > 3) {
		std::cout << "d : " << depth << endl;
		for (int i = 0;i < 8;i++)
			std::cout << i << "th child size : " << (*childs)[i]->m_index->size() << endl;
		std::cout << endl;
	}
	for (int i = 0;i < 8;i++) {
		int triangel_num = (*childs)[i]->m_index->size();
		if (triangel_num == 0) (*childs)[i] = nullptr;
		else if (triangel_num > MAX_TRIANGEL_NUM)(*childs)[i]->build_octree(mesh);
	}

}
void Octree::generate_octree(Mesh *mesh) {
	std::cout << "generate_octree called" << endl;
	m_mesh = mesh;
	BoundingBox3f bbox = m_mesh->getBoundingBox();
	m_root = new Node(new BoundingBox3f(bbox.min, bbox.max), new std::vector<int>, 0);
	int num = m_mesh->getTriangleCount();
	for (int i = 0;i <num ;i++) m_root->m_index->push_back(i);
	m_root->build_octree(m_mesh);

}
int Octree::search_octree(const Ray3f &ray) const {
	float min_t = FLT_MAX;
	int idx = -1;
	m_root->search(ray, m_mesh, min_t, idx,0);
	
	return idx;
}
void Oct_Node::search(const Ray3f &ray,Mesh *mesh,float &min_t, int &idx,int dep) {
	std::cout << "\ndep : " << dep << endl;
	if (m_childs == nullptr) {
		for (int i = 0;i < m_index->size();i++) {
			float u, v, t;
			std::cout << "a" << endl;
			if (mesh->rayIntersect(i, ray, u, v, t)) {
				if (min_t > t) {
					min_t = t;
					idx = i;
				}
			}
			std::cout << "minimum index : " << idx << endl;
		}
	}
	else{
		for (int i = 0;i < 8;i++) {
			std::cout << "b " << m_index->size()<<endl;
			if ((*m_childs)[i] != nullptr && (*m_childs)[i]->m_bbox->rayIntersect(ray)) {
				std::cout << "c" <<i<< endl;
				(*m_childs)[i]->search(ray, mesh, min_t, idx, dep + 1);
			}
		}
	}
}
NORI_NAMESPACE_END
