#ifndef THREAD_GURAD_H
#define THREAD_GURAD_H

#if !defined(THREAD_ANNOTATION_ATTRIBUTE__)
#if defined(__clang__)




#ifndef GUARDED_BY
#define GUARDED_BY(x) _attribute__(guarded_by(x))
#endif

#ifndef PT_GUARDED_BY
#define PT_GUARDED_BY(x) THREAD_ANNOTATION_ATTRIBUTE__(pt_guarded_by(x))
#endif

#ifndef EXCLUSIVE_LOCKS_REQUIRED
#define EXCLUSIVE_LOCKS_REQUIRED(...) \
    _attribute__(exclusive_locks_required(__VA_ARGS__))
#endif