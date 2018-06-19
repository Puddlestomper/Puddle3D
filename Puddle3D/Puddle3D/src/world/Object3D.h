#pragma once

#include "Eigen/Dense"

class Object3D
{
private:
	Eigen::RowVector3f m_position; //Position in global space
	Eigen::Matrix3f m_transform; //Rotation/Scale/Anything other than translation variable variable
	//Vector/array of points (defined relative to position)
	//Vector of triangles?
public:
	//Return the position of a global point in the local co-ordinate space of this object
	inline Eigen::RowVector3f getLocalPos(Eigen::RowVector3f point) const { return (point - m_position) * m_transform; } //CHECK THIS
	//Return the position of a global point in the upright co-ordinate space of this object
	inline Eigen::RowVector3f getUprightPos(Eigen::RowVector3f point) const { return point - m_position; } //CHECK
private:
	//Return the position of a local point in the global co-ordinate space of this object
	inline Eigen::RowVector3f globalPos(Eigen::RowVector3f point) const { return point * m_transform.inverse() + m_position; } //CHECK
	//Return the position of a local point in the upright co-ordinate space of this object
	inline Eigen::RowVector3f uprightPos(Eigen::RowVector3f point) const { return point * m_transform.inverse(); } //CHECK

	//Add transform function: Rotate, scale, move, etc.
};