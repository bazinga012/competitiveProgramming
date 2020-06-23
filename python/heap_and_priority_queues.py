# heap
import itertools
import heapq
a = [2, 10, 6, 9, 4, 1, 5]
heapq.heapify(a)  # min heap
heapq.heappop(a)  # smallest element

b = [2, 10, 6, 9, 4, 1, 5]
heapq.heapify()

heapq.heapify([-i for i in b])

# see heapq merge function returns a generator

# priority queue
# Objectives:
"""
Sort stability: how do you get two tasks with equal priorities to be returned in the order they were originally added?

Tuple comparison breaks for (priority, task) pairs if the priorities are equal and the tasks do not have a default comparison order.

If the priority of a task changes, how do you move it to a new position in the heap?

Or if a pending task needs to be deleted, how do you find it and remove it from the queue?
"""
pq = []
task_to_heap_entry_of_task = {}
REMOVED = 'REMOVED'  # for handling delete and update
counter = itertools.count()


def add_task(task, priority=0):
    remove_task_if_already_present(task)
    # for making it stable ie. if priority are same value inserted first will be fetched
    count = next(counter)
    entry = [priority, count, task]
    task_to_heap_entry_of_task[task] = entry
    heapq.heappush(pq, entry)


def remove_task_if_already_present(task):
    if task in task_to_heap_entry_of_task:
        heap_entry_of_task = task_to_heap_entry_of_task.pop(task)
        heap_entry_of_task[-1] = REMOVED


def pop_task():
    while pq:
        priority, count, task = heapq.heappop(pq)
        if task is not REMOVED:
            del task_to_heap_entry_of_task[task]
            return task
