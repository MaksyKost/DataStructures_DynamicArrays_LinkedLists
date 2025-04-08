#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

// klasa bazowa
class Structure {
    public:
        virtual void addBegin(int val) = 0;
        virtual void addEnd(int val) = 0;
        virtual void addIndex(int val, int index) = 0;
        virtual void removeBegin() = 0;
        virtual void removeEnd() = 0;
        virtual void removeIndex(int index) = 0;
        virtual int find(int val) = 0;
        virtual void print() = 0;
        virtual void fillRandom(int count, int seed) = 0;
        virtual int getSize() const =  0;
        virtual ~Structure() {}
};

class ArrayList : public Structure {
    private:
        int* arr;
        int size;
        int capacity;
        void resize();

    public:
        ArrayList(int initialCapacity = 10);
        ~ArrayList();
        virtual void addBegin(int val) override;
        virtual void addEnd(int val) override;
        virtual void addIndex(int val, int index) override;
        virtual void removeBegin() override;
        virtual void removeEnd() override;
        virtual void removeIndex(int index) override;
        virtual int find(int val) override;
        virtual void print() override;
        virtual int getSize() const override;
        virtual void fillRandom(int count, int seed) override;
};

#endif // DYNAMICARRAY_H