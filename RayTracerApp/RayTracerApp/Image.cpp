#include "Image.hpp"


Image::Image()
= default;

Image::Image(std::string filename)
{
	this->filename_ = filename;
	this->size_ = 1;
	
	this->data_ = ImageMisc::LoadPictureData(this->filename_.c_str(), &this->width_, &this->height_, &this->channels_);
	std::vector<unsigned char> temp;
	this->main_data_ = std::vector<unsigned char>(width_ * height_ * 4);
	this->save_path_.append("result_images/");
	this->save_path_.append(std::filesystem::u8path(filename_).filename().u8string());
}

Image::Image(unsigned char* data, const int width, const int height)
{
	this->width_ = width;
	this->height_ = height;
	this->size_ = 1;
}

int& Image::get_height()
{
	return height_;
}

void Image::set_height(const int height)
{
	height_ = height;
}

int& Image::get_width()
{
	return width_;
}

void Image::set_width(const int width)
{
	width_ = width;
}

std::string Image::get_filename() const
{
	return filename_;
}

void Image::set_filename(const char* filename)
{
	filename_ = filename;
}

unsigned char* Image::get_data() const
{
	return data_;
}

void Image::set_data(unsigned char* data)
{
	data_ = data;
}

float Image::get_size() const
{
	return size_;
}

void Image::set_size(float size)
{
	size_ = size;
}

std::vector<unsigned char> Image::get_main_data() const
{
	return main_data_;
}

void Image::set_main_data(std::vector<unsigned char> main_data)
{
	main_data_ = main_data;
}

int Image::get_channels() const
{
	return channels_;
}

void Image::set_channels(int channels)
{
	channels_ = channels;
}

std::string Image::get_save_path() const
{
	if(save_path_.length() > 0)
		return save_path_;
	return filename_;
}

void Image::set_save_path(const std::string& save_path)
{
	save_path_ = save_path;
}

std::vector<float> Image::getReds(Colors color)
{
	std::vector<float> reds;
	std::map<int, int> value_map;

	for (auto i = 0; i < 256; i++)
	{
		value_map.insert(std::pair<int, int>(i, 0));
	}
	
	for (auto i = static_cast<int>(color); i < width_ * height_ * 4; i += 4)
	{
		value_map[main_data_[i]]++;
	}

	reds.reserve(value_map.size());
	for (auto& it : value_map)
	{
		reds.push_back(it.second);
	}
	return reds;
}
	std::vector<float> Image::get_red_histogram() const
	{
		return red_histogram_;
	}

	void Image::set_red_histogram(const std::vector<float>& red_histogram)
	{
		red_histogram_ = red_histogram;
	}

	std::vector<float> Image::get_green_histogram() const
	{
		return green_histogram_;
	}

	void Image::set_green_histogram(const std::vector<float>& green_histogram)
	{
		green_histogram_ = green_histogram;
	}

	std::vector<float> Image::get_blue_histogram() const
	{
		return blue_histogram_;
	}

	void Image::set_blue_histogram(const std::vector<float>& blue_histogram)
	{
		blue_histogram_ = blue_histogram;
	}

	float Image::sum_histogram_elements(Colors color, int n) const
	{
		std::vector<float> histogram;
		float sum = 0;
	
		if(color == Colors::RED)
		{
			histogram = get_red_histogram();
		}
		else if(color == Colors::GREEN)
		{
			histogram = get_green_histogram();
		}
		else if(color == Colors::BLUE)
		{
			histogram = get_blue_histogram();
		}
		
		for(auto i = 0; i <= n; i++)
		{
			sum += histogram[i];
		}
		return sum;
	}
