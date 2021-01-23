.PHONY: all clean distclean dist test

ifeq ($(PREFIX),)
    PREFIX := /usr/local/
endif


DIST_NAME := xoroshiro16
DIST_VERSION := 0.0.1

SOURCE_LIST := Makefile LICENSE.md README.md src/ docs/ test/

HAS_GCC := $(shell which gcc >/dev/null ; echo $$?)
HAS_DIEHARDER := $(shell which dieharder >/dev/null ; echo $$?)


all: test

clean:
	-@$(RM) -r bin/
	-@$(RM) -r build/

distclean: clean
	-@$(RM) -r dist/
	-@$(RM) -r target/

dist: src/xoroshiro16.c src/xoroshiro16.h
	@$(RM) -r build/dist/
	@mkdir -p build/dist/$(DIST_NAME)-$(DIST_VERSION)/
	@cp -r $(SOURCE_LIST) build/dist/$(DIST_NAME)-$(DIST_VERSION)/
	@tar -cz -C build/dist/  --owner=0 --group=0 -f build/dist/$(DIST_NAME)-$(DIST_VERSION).tar.gz $(DIST_NAME)-$(DIST_VERSION)/
	@mkdir -p dist/
	@mv build/dist/$(DIST_NAME)-$(DIST_VERSION).tar.gz dist/
	@echo Output at dist/$(DIST_NAME)-$(DIST_VERSION).tar.gz

test:
	$(if $(findstring 0,$(HAS_GCC)),,$(error No 'gcc' in path, consider installing 'gcc' package))
	$(if $(findstring 0,$(HAS_DIEHARDER)),,$(error No 'dieharder' in path, consider installing 'dieharder' package))
	-@rm -r build 2>/dev/null || true
	@mkdir -p build
	@gcc -o build/xoroshiro16test src/*.c
	@mkdir -p bin/
	@cp build/xoroshiro16test bin/xoroshiro16test
	@cd bin && ../test/test.sh
