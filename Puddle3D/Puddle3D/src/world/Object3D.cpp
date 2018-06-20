#include "Object3D.h"

#include <cmath>

void Object3D::scale(const float& factor)
{
	m_scale *= factor;
	updateTransform();
}

void Object3D::setScale(const float& factor)
{
	m_scale = factor;
	updateTransform();
}

void Object3D::rotateX(const float& degrees)
{
	m_xDegrees += degrees;
	updateTransform();
}

void Object3D::rotateY(const float& degrees)
{
	m_yDegrees += degrees;
	updateTransform();
}


void Object3D::rotateZ(const float& degrees)
{
	m_zDegrees += degrees;
	updateTransform();
}

void Object3D::updateTransform()
{
	Eigen::Matrix3f xRotate, yRotate, zRotate;
	double rad = m_xDegrees * EIGEN_PI / 180.0;
	xRotate << 1,		  0,		0,
			   0,  cos(rad), sin(rad),
			   0, -sin(rad), cos(rad);
	rad = m_yDegrees * EIGEN_PI / 180.0;
	yRotate << cos(rad), 0, -sin(rad),
					  0, 1,			0,
			   sin(rad), 0,  cos(rad);
	rad = m_zDegrees * EIGEN_PI / 180.0;
	zRotate <<  cos(rad), sin(rad), 0,
			   -sin(rad), cos(rad), 0,
					   0,		 0, 1;

	m_transform = m_scale * (xRotate * yRotate * zRotate);
	updateVArray();
}