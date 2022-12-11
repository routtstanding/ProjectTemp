#pragma once

template <typename T>
class Visitor
{
public:
	virtual void visit(T entity) const = 0;
	//this is a pure virtual function

};