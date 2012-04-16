#pragma once
/************************************************************************/
/* ImageManager
/* ------------
/* A manager for SFML images
/************************************************************************/
#include <SFML/Graphics/Image.hpp>

#include <string>
#include <set>
#include <map>

typedef std::map<std::string, sf::Image> StringImageMap;
typedef StringImageMap::iterator         StringImageMapIter;
typedef StringImageMap::const_iterator   StringImageMapConstIter;


class ImageManager
{
private:
	StringImageMap images;
	std::set<std::string> resourceDirs;

public:
	static ImageManager& get() { static ImageManager m; return m; }

	const sf::Image& getImage(const std::string& filename);

	void deleteImage(const sf::Image& image);
	void deleteImage(const std::string& filename);

	void addResourceDir(const std::string& directory);
	void delResourceDir(const std::string& directory);

private:
	// Class is singleton
	ImageManager();
	ImageManager(const ImageManager& other);
	ImageManager& operator=(const ImageManager& other);
};
