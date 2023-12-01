import TasksModel from '../models/task.models'
import { UserToken } from '../types/types'
import { Request, Response } from 'express'
import { State, Importance } from '../types/types'
import projectModel from '../models/project.model'

interface RequestWithUserData extends Request {
  userData?: UserToken
}

export const getTasks = async (req: RequestWithUserData, res: Response) => {
  const { project } = req.body

  const userId = req.userData?._id

  if (!userId) {
    return res.status(401).json({ message: 'Unauthorized' })
  }
  const tasks = await TasksModel.find({
    project: project,
    user: userId
  })
  return res.json(tasks)
}

export const createTask = async (req: RequestWithUserData, res: Response) => {
  const { project, title, description, deadline, importance } = req.body
  if (Object.values(Importance).includes(importance)) {
    try {
      const existingTitle = await TasksModel.findOne({
        project: project,
        title: title
      })
      if (existingTitle) {
        const Project = await projectModel.findById(project)
        return res.status(409).json({
          message: `The title '${title}' already exists for in the project name '${Project?.nameproject}'`
        })
      }
      const userId = req.userData?._id
      const username = req.userData?.username
      if (!username || !userId) {
        return res.status(401).json({ message: 'Unauthorized' })
      }
      const newTask = new TasksModel({
        project,
        createdBy: username,
        user: userId,
        title,
        description,
        deadline,
        importance,
        state: State.Finished
      })
      const savedTask = await newTask.save()
      return res.status(201).json(savedTask)
    } catch (error: any) {
      return res
        .status(500)
        .json({ message: 'Error to save task', error: error.message })
    }
  } else {
    return res.status(400).json({ message: 'Importance not valid' })
  }
}

export const getTask = async (req: RequestWithUserData, res: Response) => {
  const taskId = req.params.id

  try {
    const userId = req.userData?._id

    if (!userId) {
      return res.status(401).json({ message: 'Unauthorized' })
    }

    const task = await TasksModel.findOne({
      _id: taskId,
      user: userId
    })

    if (!task) {
      return res.status(404).json({ message: 'task not found' })
    }

    return res.json(task)
  } catch (error: any) {
    return res
      .status(500)
      .json({ message: 'Error to get tasks', error: error.message })
  }
}

export const deleteTask = async (req: RequestWithUserData, res: Response) => {
  const taskId = req.params.id
  const userId = req.userData?._id

  if (!taskId || !userId) {
    return res.status(401).json({ message: 'Unauthorized' })
  }

  try {
    const task = await TasksModel.findByIdAndDelete({
      _id: taskId,
      user: userId
    })
    if (!task) {
      return res.status(404).json({ message: 'task not found' })
    }

    return res.status(204).json({ message: 'task successfully deleted' })
  } catch (error: any) {
    return res
      .status(500)
      .json({ message: 'Error to get tasks', error: error.message })
  }
}

export const updateTask = async (req: RequestWithUserData, res: Response) => {
  const taskId = req.params.id
  const userId = req.userData?._id

  if (!taskId || !userId) {
    return res.status(401).json({ message: 'Unauthorized' })
  }

  try {
    const task = await TasksModel.findOneAndUpdate(
      { _id: taskId, user: userId },
      req.body,
      {
        new: true
      }
    )

    if (!task) {
      return res.status(404).json({ message: 'task not found' })
    }
    return res.json(task)
  } catch (error: any) {
    return res
      .status(500)
      .json({ message: 'Error to get tasks', error: error.message })
  }
}
