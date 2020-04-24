#include "Mesh.h"

#define TINYOBJLOADER_IMPLEMENTATION // define this in only *one* .cc
#include "tiny_obj_loader.h"

Mesh::Mesh()
{
	this->Shape_ = std::make_shared <std::vector<Triangle>>();
	this->Shape_->clear();

	this->Faces_ = std::make_shared<std::vector<Face>>();
	this->Verticles_ = std::make_shared<std::vector<Vector>>();
	this->Normals_ = std::make_shared<std::vector<Vector>>();
}

void Mesh::PutNextTriangle(Triangle t)
{
	this->Shape_->push_back(t);
}

std::vector<std::string> split(const std::string& str, const char& delimit)
{
	std::vector<std::string> result;
	std::string data;
	std::stringstream ss(str);
	while (getline(ss, data, delimit))
	{
		result.push_back(data);
	}
	return result;
}

void Mesh::ReadMeshFromFile(std::string filename)
{
	tinyobj::attrib_t attrib;
	std::vector<tinyobj::shape_t> shapes;
	std::vector<tinyobj::material_t> materials;

	std::string warn;
	std::string err;

	bool ret = tinyobj::LoadObj(&attrib, &shapes, &materials, &warn, &err, filename.c_str());

	if (!warn.empty()) {
		std::cout << warn << std::endl;
	}

	if (!err.empty()) {
		std::cerr << err << std::endl;
	}

	if (!ret) {
		exit(1);
	}


	int countA = 0;
	int countb = 0;

	std::vector<Vector> tris;

	for (size_t s = 0; s < shapes.size(); s++)
	{
		// Loop over faces(polygon)
		size_t index_offset = 0;
		for (size_t f = 0; f < shapes[s].mesh.num_face_vertices.size(); f++)
		{
			int fv = shapes[s].mesh.num_face_vertices[f];

			// Loop over vertices in the face.
			for (size_t v = 0; v < fv; v++)
			{
				// access to vertex
				tinyobj::index_t idx = shapes[s].mesh.indices[index_offset + v];
				tinyobj::real_t vx = attrib.vertices[3 * idx.vertex_index + 0];
				tinyobj::real_t vy = attrib.vertices[3 * idx.vertex_index + 1];
				tinyobj::real_t vz = attrib.vertices[3 * idx.vertex_index + 2];
				tinyobj::real_t nx = attrib.normals[3 * idx.normal_index + 0];
				tinyobj::real_t ny = attrib.normals[3 * idx.normal_index + 1];
				tinyobj::real_t nz = attrib.normals[3 * idx.normal_index + 2];
				tinyobj::real_t tx = attrib.texcoords[2 * idx.texcoord_index + 0];
				tinyobj::real_t ty = attrib.texcoords[2 * idx.texcoord_index + 1];

				tris.push_back(Vector(vx, vy, vz));
			}
			index_offset += fv;

			// per-face material
			shapes[s].mesh.material_ids[f];
		}
	}

	for (int k = 0; k < tris.size(); k = k + 3)
	{
		this->Shape_->push_back(Triangle(tris[k], tris[k + 1], tris[k + 2]));
	}
}

void Mesh::AddVertex(float x, float y, float z)
{
	this->Verticles_->push_back(Vector(x, y, z));
}

void Mesh::AddFace(int a, int b, int c)
{
	this->Faces_->push_back(Face(AbsoludeNdx(a), AbsoludeNdx(b), AbsoludeNdx(c)));
}

void Mesh::ComputeNormals()
{
	std::vector<std::vector<Vector>> normalsForVerticles(this->Verticles_->size());
	std::vector<Vector> tNormals(this->Verticles_->size());

	for (int i = 0; i < this->Verticles_->size(); i++)
	{
		normalsForVerticles.push_back(std::vector<Vector>());
		tNormals.push_back(Vector());
	}

	for (int i = 0; i < this->Faces_->size(); i++)
	{
		Vector normal = GetNormal(this->Faces_->data()[i]);
		normalsForVerticles[this->Faces_->data()[i].A].push_back(normal);
		normalsForVerticles[this->Faces_->data()[i].B].push_back(normal);
		normalsForVerticles[this->Faces_->data()[i].C].push_back(normal);
	}

	for (int i = 0; i < normalsForVerticles.size(); i++)
	{
		tNormals[i] = (normalsForVerticles[i][0] + normalsForVerticles[i][1]).NormalizeProduct();
	}
}

int Mesh::AbsoludeNdx(int n)
{
	return n < 0 ? this->Verticles_->size() - n : n - 1;
}

Vector Mesh::GetNormal(Face face)
{
	Vector edgeBA = this->Verticles_->data()[face.B] - this->Verticles_->data()[face.A];
	Vector edgeCA = this->Verticles_->data()[face.C] - this->Verticles_->data()[face.A];

	Vector res = edgeBA.Cross(edgeCA).NormalizeProduct();

	return res;
}
