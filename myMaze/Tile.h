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
	std::shared_ptr<GameObject>& getObjectRef();
	void setObject(std::shared_ptr<GameObject> _object);

	void notify() override;

};

std::shared_ptr<Tile> operator+=(std::shared_ptr<Tile> curTile, std::shared_ptr<Tile> otherTile);
std::shared_ptr<Tile> operator-=(std::shared_ptr<Tile> curTile, std::shared_ptr<Tile> otherTile);