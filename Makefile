all:
	+$(MAKE) -C day1
	+$(MAKE) -C day2	
	+$(MAKE) -C day3	
	+$(MAKE) -C day4
	+$(MAKE) -C day5	
	+$(MAKE) -C day6
	+$(MAKE) -C day7
	+$(MAKE) -C day8
	+$(MAKE) -C day9
	+$(MAKE) -C day10

clean:
	rm -rf target/*
