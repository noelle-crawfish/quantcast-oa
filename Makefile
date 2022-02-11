most_active_cookie: cookie_tool.cpp cookie_data.cpp
	g++ -o  most_active_cookie cookie_tool.cpp cookie_data.cpp

run_tests: tests.cpp cookie_data.cpp
	g++ -o run_tests tests.cpp cookie_data.cpp

clean:
	$(RM) most_active_cookie
