#pragma once
#include "__fwd.h"
#include <vector>
#include <memory>


class Observable {
protected:
	std::vector<std::shared_ptr<Observer>> subscribers;
public:
	Observable() = default;
	~Observable() = default;
	std::vector<std::shared_ptr<Observer>>& getSubs();
	virtual void notify() = 0;
};


class Tile : public Observable {
private:
	std::shared_ptr<GameObject> object;
public:
	Tile(std::shared_ptr<GameObject> object = nullptr);
	~Tile() = default;

	std::shared_ptr<GameObject> getObject();
	void setObject(std::shared_ptr<GameObject> _object);

	void notify() override;

};

Tile& operator+=(Tile& curTile, Tile& otherTile);
Tile& operator-=(Tile& curTile, Tile& otherTile);