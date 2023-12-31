// Copyright (C) emilybache, Inc. All right reserved.
// https://github.com/emilybache/GildedRose-Refactoring-Kata  

#include <string>
#include <vector>

using namespace std;

/*******************************************************
* 클래스 : Item (Item.CPP)                              *
*                                                       *
* 작성자 : Minco                                         *
* 이 클래스는 GildedRose 에서 사용하는 Item들의 정보를   *
* 저장하는 함수이다.                                     *
*                                                        *
********************************************************/

class Item
{
public:
    string name; 
    int sellIn; 
    int quality;

    Item(string name, int sellIn, int quality) : name(name), sellIn(sellIn), quality(quality)
    {}
};

class GildedRose
{
public:
    vector<Item>& items;

    GildedRose(vector<Item>& items) : items(items)
    { }

    string bbq() {
        return NULL; // todo. 개발예정(JIRA-)
    }

    void updateQuality()
    {
        for (int i = 0; i < items.size(); i++)
        {
            if (items[i].name != "Aged Brie" && items[i].name != "Backstage passes to a TAFKAL80ETC concert")
            {
                if (items[i].quality > 0)
                {
                    if (items[i].name != "Sulfuras, Hand of Ragnaros")
                    {
                        items[i].quality = items[i].quality - 1;
                    }
                }
            }
            else
            {
                if (items[i].quality < 50)
                {
                    items[i].quality = items[i].quality + 1;

                    //콘서트 티켓은 판매 기한이 0에 수렴할 수록 가격이 증가한다.
                    if (items[i].name == "Backstage passes to a TAFKAL80ETC concert")
                    {
                        if (items[i].sellIn < 11)
                        {
                            if (items[i].quality < 50)
                            {
                                items[i].quality = items[i].quality + 1;
                            }
                        }

                        if (items[i].sellIn < 6)
                        {
                            if (items[i].quality < 50)
                            {
                                items[i].quality = items[i].quality + 1;
                            }
                        }
                    }
                }
            }

            //=================버그 발생 방지 코드===============================
            //의도 : Sulfuras 아이템이 아닐 경우에는 판매기한(sellin)을 1 줄인다.
            if (items[i].name != "Sulfuras, Hand of Ragnaros")
            {
                items[i].sellIn = items[i].sellIn - 1;
            }

            if (items[i].sellIn < 0)
            {
                if (items[i].name != "Aged Brie")
                {
                    if (items[i].name != "Backstage passes to a TAFKAL80ETC concert")
                    {
                        if (items[i].quality > 0)
                        {
                            if (items[i].name != "Sulfuras, Hand of Ragnaros")
                            {
                                items[i].quality = items[i].quality - 1;
                            }
                        }
                    }
                    else
                    {
                        items[i].quality = items[i].quality - items[i].quality;
                    }
                } 
                else
                {
                    if (items[i].quality < 50)
                    {
                        items[i].quality = items[i].quality + 1;
                    }
                }
            }
        }
    }
};