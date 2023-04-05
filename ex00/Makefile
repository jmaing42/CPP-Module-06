NAME = ex00
OBJS = main.o AConvert.o CharConvert.o IntConvert.o FloatConvert.o DoubleConvert.o

CXXFLAGS = -Wall -Wextra -Werror


all: $(NAME)
.PHONY: all


.PHONY: clean
clean:
	rm -f $(OBJS)

.PHONY: fclean
fclean: clean
	rm -f $(NAME)

.PHONY: re
re:
	$(MAKE) fclean
	$(MAKE) all


.cpp.o:
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $<

$(NAME): $(OBJS)
	$(CXX) $(LDFLAGS) -o $@ $^
