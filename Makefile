target = lrcdemo

src = parse_lrc.c simple_list.c parser.c double_linklist.c

$(target):$(src)
	gcc -o $@ $^ 

clean:
	rm lrcdemo -rf

.PHONY: clean
