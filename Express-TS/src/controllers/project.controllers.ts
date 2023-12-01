import projectModel from '../models/project.model'
import { UserToken } from '../types/types'
import { Request, Response } from 'express'
import { State, Importance } from '../types/types'

interface RequestWithUserData extends Request {
  userData?: UserToken
}

export const getprojects = async (req: RequestWithUserData, res: Response) => {
  const userId = req.userData?._id

  if (!userId) {
    return res.status(401).json({ message: 'Unauthorized' })
  }

  const project = await projectModel.find({
    user: userId
  })

  return res.json(project)
}

export const createproject = async (
  req: RequestWithUserData,
  res: Response
) => {
  const { nameproject, description, deadline, importance } = req.body
  if (Object.values(Importance).includes(importance)) {
    try {
      const userId = req.userData?._id
      const username = req.userData?.username
      if (!username || !userId) {
        return res.status(401).json({ message: 'Unauthorized' })
      }
      const newproject = new projectModel({
        nameproject,
        createdBy: username,
        user: userId,
        description,
        deadline,
        importance,
        state: State.WithoutStarting
      })
      const saveproject = await newproject.save()
      return res.status(201).json(saveproject)
    } catch (error: any) {
      return res
        .status(500)
        .json({ message: 'Error to save project', error: error.message })
    }
  } else {
    return res.status(400).json({ message: 'Importance not valid' })
  }
}

export const getproject = async (req: RequestWithUserData, res: Response) => {
  const projectId = req.params.id

  try {
    const userId = req.userData?._id

    if (!userId) {
      return res.status(401).json({ message: 'Unauthorized' })
    }

    const project = await projectModel.findOne({
      _id: projectId,
      user: userId
    })

    if (!project) {
      return res.status(404).json({ message: 'project not found' })
    }

    return res.json(project)
  } catch (error: any) {
    return res
      .status(500)
      .json({ message: 'Error to get project', error: error.message })
  }
}

export const deleteproject = async (
  req: RequestWithUserData,
  res: Response
) => {
  const projectId = req.params.id
  const userId = req.userData?._id

  if (!projectId || !userId) {
    return res.status(401).json({ message: 'Unauthorized' })
  }

  try {
    const project = await projectModel.findByIdAndDelete({
      _id: projectId,
      user: userId
    })
    if (!project) {
      return res.status(404).json({ message: 'project not found' })
    }

    return res.status(204).json({ message: 'project successfully deleted' })
  } catch (error: any) {
    return res
      .status(500)
      .json({ message: 'Error to get project', error: error.message })
  }
}

export const updateproject = async (
  req: RequestWithUserData,
  res: Response
) => {
  const projectId = req.params.id
  const userId = req.userData?._id

  if (!projectId || !userId) {
    return res.status(401).json({ message: 'Unauthorized' })
  }

  try {
    const project = await projectModel.findOneAndUpdate(
      { _id: projectId, user: userId },
      req.body,
      {
        new: true
      }
    )

    if (!project) {
      return res.status(404).json({ message: 'project not found' })
    }

    return res.json(project)
  } catch (error: any) {
    return res
      .status(500)
      .json({ message: 'Error to get project', error: error.message })
  }
}
