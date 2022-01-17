# Chain builder
CXX := g++
CPPFILES := main.cpp Block.cpp Blockchain.cpp
INC := -Iinclude
EXE := xchain.exe 
DELETE := rm -rf

${EXE}: ${CPPFILES}  
	@echo "Start building executable..."
	@${CXX} $^ ${INC} -o $@
	@echo "Build Success"

.PHONY:
clean: 
	@echo "Deleting executable..."
	@${DELETE} ${EXE}
	@echo "Done!"
