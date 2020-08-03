#include <iostream>

class interruptible_iteration
{
public:
    interruptible_iteration(basic_iteration<double>& iter)
        : iter(iter), interrupted(false){}
    bool finished(double r)
    {
        return iter.finished(r) || interrupted.load();
    }
    void interrupt() {
        interrupted= true;
    }
    bool is_interrupted() const {
        return interrupted.load();
    }
private:
    basic_iteration<double>& iter;
    std::atomic<bool>  interrupted;
};

template <typename Solver>
class async_executor
{
public:
    async_executor(const Solver& solver)
        : my_solver(solver), my_iter{}, my_thread{}{}
    template <typename VectorB, typename VectorX,
             typename Iteration>
    void start_solve(const VectorB& b, VectorX& x,
            Iteration& iter) const
    {
        my_iter.set_iter(iter);
        my_thread= std::thread(
                [this, &b, &x](){
                    return my_solver.solve(b, x, my_iter);
                }
                );
    }
    int wait(){
        my_thread.join();
        return my_iter.error_code();
    }
    int interrupt(){
        my_iter.interrupt();
        return wait();
    }

    bool finished() const { return my_iter.iter->finished(); }
private:
    Solver          my_solver;
    mutable interruptible_iteration my_iter;
    mutable std::thread     my_thread;
};


