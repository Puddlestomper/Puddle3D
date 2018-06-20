#pragma once
#include "Eigen/Dense"

#include "SFML/Graphics/Drawable.hpp"
#include "SFML/Graphics/VertexArray.hpp"

class Object3D : public sf::Drawable
{
protected:
	Eigen::RowVector3f m_position; //Position in global space
	Eigen::Matrix3f m_transform; //Rotation/Scale/Anything other than translation variable variable
	Eigen::MatrixX3f m_points; //Vector/array of points (defined relative to position)
	//Vector of triangles?
	sf::VertexArray m_vertices;
	float m_xDegrees = 0.0f, m_yDegrees = 0.0f, m_zDegrees = 0.0f, m_scale = 1.0f;
public:
	Object3D(const Eigen::RowVector3f& position = Eigen::RowVector3f(0, 0, 0), const Eigen::Matrix3f& transform = Eigen::Matrix3f::Identity(), unsigned int vertices = 0)
		: m_position(position), m_transform(transform), m_vertices(sf::Triangles, vertices) {}
	virtual ~Object3D() {}

	//Return the position of a global point in the local co-ordinate space of this object
	inline Eigen::RowVector3f getLocalPos(Eigen::RowVector3f point) const { return (point - m_position) * m_transform; } //CHECK THIS
	//Return the position of a global point in the upright co-ordinate space of this object
	inline Eigen::RowVector3f getUprightPos(Eigen::RowVector3f point) const { return point - m_position; } //CHECK

	//Scale the object
	void scale(const float& factor);
	void setScale(const float& factor);
	void rotateX(const float& degrees); //Rotate in the x axis - Implement along with updateTransform()
	void rotateY(const float& degrees);
	void rotateZ(const float& degrees);
private:
	//Return the position of a local point in the global co-ordinate space of this object
	inline Eigen::RowVector3f globalPos(Eigen::RowVector3f point) const { return point * m_transform.inverse() + m_position; } //CHECK
	//Return the position of a local point in the upright co-ordinate space of this object
	inline Eigen::RowVector3f uprightPos(Eigen::RowVector3f point) const { return point * m_transform.inverse(); } //CHECK

	//Add transform function: Rotate, scale, move, etc.
	virtual void updateVArray() = 0;
	virtual void updateTransform();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
};