clean :

 	rm -f $(TARGETS) *~ */*~ */*.o

test:
test: $(TARGETS)
  	./tests/shutdown
  	./tests/thrdtest
  	./tests/heavy
