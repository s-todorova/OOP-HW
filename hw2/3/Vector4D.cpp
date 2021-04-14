#include "Vector4D.hpp"

Vector4D::Vector4D()
{
	vec = { 0.0,0.0,0.0,0.0 };
}

Vector4D::Vector4D(double a, double b , double c, double d)
{
	vec.push_back(a);
	vec.push_back(b);
	vec.push_back(c);
	vec.push_back(d);
}

double& Vector4D::operator[](unsigned int index)
{
	return vec[index];
}

Vector4D& Vector4D::operator=(const Vector4D& rhs)
{
	for (int i = 0; i < vec.size(); i++)
	{
		this->vec[i] = rhs.vec[i];
	}
	return *this;
}

Vector4D Vector4D::operator+(const Vector4D& rhs) const
{
	Vector4D result((vec[0] + rhs.vec[0]),(vec[1] + rhs.vec[1]),(vec[2] + rhs.vec[2]),(vec[3] + rhs.vec[3]));
	return result;
}

Vector4D& Vector4D::operator+=(const Vector4D& rhs)
{
	for (int i = 0; i < vec.size(); i++)
	{
		this->vec[i] += rhs.vec[i];
	}
	return *this;
}

Vector4D Vector4D::operator-(const Vector4D& rhs) const
{
	Vector4D result((vec[0] - rhs.vec[0]),(vec[1] - rhs.vec[1]),(vec[2] - rhs.vec[2]),(vec[3] - rhs.vec[3]));
	return result;
}

Vector4D& Vector4D::operator-=(const Vector4D& rhs)
{
	for (int i = 0; i < vec.size(); i++)
	{
		this->vec[i] -= rhs.vec[i];
	}
	return *this;
}

Vector4D Vector4D::operator*(const Vector4D& rhs) const
{
	Vector4D result = *this;
	for (int i = 0; i < vec.size(); i++)
	{
		result.vec[i] *= rhs.vec[i];
	}
	return result;
}

Vector4D& Vector4D::operator*=(const Vector4D& rhs)
{
	for (int i = 0; i < vec.size(); i++)
	{
		this->vec[i] *= rhs.vec[i];
	}
	return *this;
}

Vector4D Vector4D::operator/(const Vector4D& rhs) const
{
	Vector4D result = *this;
	for (int i = 0; i < vec.size(); i++)
	{
		result.vec[i] /= rhs.vec[i];
	}
	return result;
}

Vector4D& Vector4D::operator/=(const Vector4D& rhs)
{
	for (int i = 0; i < vec.size(); i++)
	{
		vec[i] /= rhs.vec[i];
	}
	return *this;
}

Vector4D Vector4D::operator*(const double value) const
{
	Vector4D result = *this;
	for (int i = 0; i < vec.size(); i++)
	{
		result.vec[i] *= value;
	}
	return result;
}

Vector4D& Vector4D::operator*=(const double value)
{
	for (int i = 0; i < vec.size(); i++)
	{
		this->vec[i] *= value;
	}
	return *this;
}

Vector4D Vector4D::operator/(const double value) const
{
	Vector4D result = *this;
	for (int i = 0; i < vec.size(); i++)
	{
		result.vec[i] /= value;
	}
	return result;
}

Vector4D& Vector4D::operator/=(const double value)
{
	for (int i = 0; i < vec.size(); i++)
	{
		this->vec[i] /= value;
	}
	return *this;
}

bool Vector4D::operator==(const Vector4D& rhs) const
{
	for (int i = 0; i < vec.size(); i++)
	{
		if(this->vec[i]!=rhs.vec[i])
		{
			return false;
		}
	}
	return true;
}

bool Vector4D::operator!=(const Vector4D& rhs) const
{
	return !(*this == rhs);
}

bool Vector4D::operator<(const Vector4D& rhs) const
{
	if (*this == rhs)
	{
		return false;
	}
	for (int i = 0; i < vec.size(); i++)
	{
		if (this->vec[i] == rhs.vec[i])
		{
			continue;
		}
		if (this->vec[i] > rhs.vec[i])
		{
			return false;
		}
	}
	return true;
}

bool Vector4D::operator>(const Vector4D& rhs) const
{
	if (*this == rhs)
	{
		return false;
	}
	for (int i = 0; i < vec.size(); i++)
	{
		if (this->vec[i] == rhs.vec[i])
		{
			continue;
		}
		if (this->vec[i] < rhs.vec[i])
		{
			return false;
		}
	}
	return true;
}

bool Vector4D::operator<=(const Vector4D& rhs) const
{
	return (*this < rhs || *this == rhs);
}

bool Vector4D::operator>=(const Vector4D& rhs) const
{
	return (*this > rhs || *this == rhs);
}

bool Vector4D::operator!() const
{
	for (int i = 0; i < vec.size(); i++)
	{
		if (this->vec[i] != 0)
		{
			return false;
		}
	}
	return true;
}

Vector4D Vector4D::operator-() const
{
	Vector4D result(-(this->vec[0]),-(this->vec[1]),-(this->vec[2]), -(this->vec[3]));
	return result;
}