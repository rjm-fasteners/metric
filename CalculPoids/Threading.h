#pragma once

class THREADING {
public:
	THREADING(string threadType);
	THREADING();
	~THREADING();
	string getTags();
	string getThread();

private:
	string text;
	string tags;
	string thrdTitle;
	string thrdType;

	void threading();
};