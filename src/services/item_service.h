#pragma once

#include <halley.hpp>
using namespace Halley;

#include "../item_config.h"

class ItemService : public Service
{
public:
	using MissCallback = std::function<void()>;
	
	void setItems(ItemCollection items);

	bool updateQueue();
	const ItemConfig& getItemAt(int index) const;
	void popQueue();

	const ItemConfig& getItemConfig(const String id) const;

	int getItemLevel(const String& id) const;
	void onItemDone(const String& id, bool itemOK);
	void onMiss();

	int getItemMult(int level) const;
	int getMult() const;
	int getScore() const;
	int getHealth() const;

	bool isAlive() const;

	void flagRestart();
	bool needsRestart() const;

	void setMissCallback(MissCallback callback);

private:
	ItemCollection items;
	std::vector<String> itemQueue;
	std::map<String, int> itemLevels;

	int score = 0;
	int mult = 10;
	int health = 10;

	int nItemsComplete = 0;

	bool restart = false;

	MissCallback callback;

	void addNextItem();
};