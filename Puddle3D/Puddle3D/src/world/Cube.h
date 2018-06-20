#pragma once

#include "Object3D.h"

class Cube : public Object3D
{
private:
	
public:
	Cube(const Eigen::RowVector3f& position = Eigen::RowVector3f(0, 0, 0), const Eigen::Matrix3f& transform = Eigen::Matrix3f::Identity());
private:
	void updateVArray() override;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};